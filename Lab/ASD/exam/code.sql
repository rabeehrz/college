CREATE TABLE Customer (
	CustomerId INT,
	MeterType INT,
	PrevReading INT,
	CurrReading INT,
	CustomerType CHAR(1),
	BillAmount FLOAT,
	LastBillPayment CHAR(1)
);

CREATE TABLE Bill (
	CustomerId INT,
	BillDate DATE,
	Fixedcharge FLOAT,
	Energycharge FLOAT,
	Surcharge FLOAT,
	NetAmount FLOAT
);

CREATE OR REPLACE FUNCTION energyCharge(prev in FLOAT , curr in FLOAT, ctype in FLOAT)
RETURNS FLOAT AS echarge
DECLARE
  echarge integer;
BEGIN
  RETURN 5.8;
END;
$echarge$ LANGUAGE plpgsql;
-- 
CREATE OR REPLACE FUNCTION dues()
  RETURNS TRIGGER 
  AS
$$
BEGIN
	IF (OLD.LastBillPayment = 'N') THEN
  raise info 'Previous dues for customer is %', OLD.BillAmount;
  END IF;

  RETURN NEW;
END;
$$
LANGUAGE PLPGSQL;


CREATE TRIGGER dues_trigger
AFTER UPDATE OF BillAmount ON Customer
FOR EACH ROW
EXECUTE PROCEDURE dues();

--------

INSERT INTO Customer
VALUES
(10005,1,3500,3550,'R',0,'N'),
(10004,3,4800,4989,'C',0,'Y'),
(10003,1,5600,5700,'I',0,'Y'),
(10008,3,5700,6000,'A',0,'N'),
(10002,3,4890,5042,'C',0,'Y');

INSERT INTO Bill
VALUES
(10005,'2020-09-24',40,82,4.1,126.1),
(10005,'2020-07-24',40,70,3.5,113.5),
(10008,'2020-09-24',120,187.5,18.75,326.25);

-----

CREATE OR REPLACE PROCEDURE updateBillAmount(
  id int
)
AS
$$
DECLARE
  amount float;
BEGIN
  SELECT COALESCE(SUM(NetAmount),0) INTO amount FROM Bill WHERE CustomerId=id;
  
  UPDATE Customer
  SET BillAmount=amount
  WHERE CustomerId=id;

  commit;
END;
$$
LANGUAGE PLPGSQL;

--

CREATE OR REPLACE FUNCTION calcEnergyCharge()
RETURNS VOID as $$
DECLARE
    energy_charge DECIMAL(10,2);
    units INT;
    rec RECORD;
    cur CURSOR
        FOR SELECT * FROM Customer;
BEGIN
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN NOT FOUND;
        units=rec.CurrReading-rec.PrevReading;
        IF units < 101 THEN
        	IF rec.CustomerType = 'A' THEN
        		energy_charge = units * 1; 
        	ELSIF rec.CustomerType = 'I' THEN
        		energy_charge = units * 1.25; 
        	ELSIF rec.CustomerType = 'C' THEN
        		energy_charge = units * 1.5; 
        	ELSIF rec.CustomerType = 'R' THEN
        		energy_charge = units * 1.3;
        	END IF;
        ELSIF units <201 THEN
        	IF rec.CustomerType = 'A' THEN
        		energy_charge = (100 * 1) + ((units-100) * 1.25); 
        	ELSIF rec.CustomerType = 'I' THEN
        		energy_charge = 100 * 1.25+ ((units-100) * 1.3);  
        	ELSIF rec.CustomerType = 'C' THEN
        		energy_charge = 100 * 1.5 + ((units-100) * 1.6); 
        	ELSIF rec.CustomerType = 'R' THEN
        		energy_charge = 100 * 1.3 + ((units-100) * 1.4); 
        	END IF;
        ELSE
        	IF rec.CustomerType = 'A' THEN
        		energy_charge = units * 1.75; 
        	ELSIF rec.CustomerType = 'I' THEN
        		energy_charge = units * 1.5; 
        	ELSIF rec.CustomerType = 'C' THEN
        		energy_charge = units * 2; 
        	ELSIF rec.CustomerType = 'R' THEN
        		energy_charge = units * 1.6;
        	END IF;
        END IF;
        INSERT INTO Bill (CustomerId,Energycharge)
			VALUES (rec.CustomerId,energy_charge); 	
    END LOOP;
    CLOSE cur;
END;
$$ LANGUAGE plpgsql;

----

CREATE OR REPLACE FUNCTION calcNetAmount()
RETURNS VOID as $$
DECLARE
    net_amount DECIMAL(10,2);
    rec RECORD;
    cur CURSOR
        FOR SELECT * FROM Customer AS C,Bill AS B
        	WHERE C.CustomerId=B.CustomerId; 
BEGIN
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN NOT FOUND;
        IF rec.BillDate IS NULL THEN
        	IF rec.MeterType = 1 THEN
        		rec.Fixedcharge = 40 + 35;
        		rec.Surcharge = 0.05*rec.Energycharge;
        	ELSIF rec.MeterType = 3 THEN
        		rec.Fixedcharge = 120 + 35;
        		rec.Surcharge = 0.1 * rec.Energycharge;
        	END IF;
        	rec.NetAmount = rec.Fixedcharge + rec.Energycharge + rec.Surcharge;
        	UPDATE Bill SET BillDate = CURRENT_DATE, Fixedcharge=rec.Fixedcharge,Surcharge = rec.Surcharge, NetAmount= rec.NetAmount
				WHERE CustomerId = rec.CustomerId AND BillDate IS NULL;    		
        END IF;
    END LOOP;
    CLOSE cur;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION calcEnergyCharge()
RETURNS VOID as $$
BEGIN
  
END;
$$ LANGUAGE plpgsql;

--

CREATE or REPLACE FUNCTION update_bill_amount() RETURNS VOID 
AS $$
DECLARE
    c_cust_list CURSOR FOR    
        SELECT * FROM Customer;
    c_cust_id Customer.CustomerId%type;
BEGIN
    OPEN c_cust_list;
    LOOP
    FETCH c_cust_list INTO c_cust_id;
        EXIT WHEN NOT FOUND;
            CALL updateBillAmount(c_cust_id);
    END LOOP;
END;
$$
LANGUAGE plpgsql;

SELECT FROM update_bill_amount();