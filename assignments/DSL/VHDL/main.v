// 8x1 Multiplexer
// Project By:
// Jacob Abraham - Roll No: 24
// Mohammed Rabeeh - Roll No: 35 

module mux_3x8(in,out,sel);

//For the input line signal
input [7:0]in;

//For the selection line signal
input [2:0]sel;

//Output line
output out;

reg out;
wire [2:0]sel;
wire [7:0]in;

always @(sel or in)
begin 

//Choose the required input line according to selection line
//Assign ‘out’ as the required ‘in’
if (sel == 0)
out = in[0];

if (sel == 1)
out = in[1];

if (sel == 2)
out = in[2];

if (sel == 3)
out = in[3];

if (sel == 4)
out = in[4];

if (sel == 5)
out = in[5];

if (sel == 6)
out = in[6];

if (sel == 7)
out = in[7];
end
endmodule 