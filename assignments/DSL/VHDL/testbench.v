// 8x1 Multiplexer
// Project By:
// Jacob Abraham - Roll No: 24
// Mohammed Rabeeh - Roll No: 35 

module mux_3x8_tb;

//For the output line
wire out;

//For the selection line signal
reg [2:0]sel;

//For the input line signal
reg [7:0]in;

mux_3x8 mux( .out(out), .in(in), .sel(sel) );

Initial begin
$monitor(sel,in,out);

//The selection and input line values
sel=3’b000;
in=8’b10111011;

end

always #20 sel=sel+3’b001;

endmodule
