
// Pardis Pashakhanloo
// 91106449

module test;

	wire done;
	wire [31:0] enc_v0, enc_v1;

	reg [31:0] delta;
	reg [31:0] k0, k1, k2, k3;
	reg [31:0] _v0, _v1;
	//reg [31:0] step;
	reg clk;

	TEA tea(done, enc_v0, enc_v1, delta, k0, k1, k2, k3, _v0, _v1, clk);

	always @(posedge done)
		$display("done=%b, enc_v0=%d, enc_v1=%d", done, enc_v0, enc_v1);

	initial clk = 1'b0;
	always #5 clk = ~clk;

	initial
	begin
		delta = 10;
		k0 = 5;
		k1 = 4;
		k2 = 3;
		k3 = 7;
		_v0 = 13;
		_v1 = 17;
	end

endmodule
