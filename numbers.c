void print2(int x)
{
	setColumn(x);
	dis_cmd_1(0x43);
	setColumn(x+1);
	dis_cmd_1(0x85);
	setColumn(x+2);
	dis_cmd_1(0x89);
	setColumn(x+3);
	dis_cmd_1(0x71);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x00);
	setColumn(x+6);
	dis_cmd_1(0x00);
	setColumn(x+7);
	dis_cmd_1(0x00);
	setColumn(x+8);
	dis_cmd_1(0x00);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x00);
	setColumn(x+11);
	dis_cmd_1(0x00);
	setColumn(x+12);
	dis_cmd_1(0x00);
	setColumn(x+13);
	dis_cmd_1(0x00);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}	
	
void print4(int x)
{
	setColumn(x);
	dis_cmd_1(0xF0);
	setColumn(x+1);
	dis_cmd_1(0x10);
	setColumn(x+2);
	dis_cmd_1(0x10);
	setColumn(x+3);
	dis_cmd_1(0xFF);
	setColumn(x+4); 
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x00);
	setColumn(x+6);
	dis_cmd_1(0x00);
	setColumn(x+7);
	dis_cmd_1(0x00);
	setColumn(x+8);
	dis_cmd_1(0x00);
	setColumn(x+9); 
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x00);
	setColumn(x+11);
	dis_cmd_1(0x00);
	setColumn(x+12);
	dis_cmd_1(0x00);
	setColumn(x+13);
	dis_cmd_1(0x00);
	setColumn(x+14); 
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}	
	
	void print8(int x)
{
	setColumn(x);
	dis_cmd_1(0x76);
	setColumn(x+1);
	dis_cmd_1(0x89);
	setColumn(x+2);
	dis_cmd_1(0x89);
	setColumn(x+3);
	dis_cmd_1(0x76);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x00);
	setColumn(x+6);
	dis_cmd_1(0x00);
	setColumn(x+7);
	dis_cmd_1(0x00);
	setColumn(x+8);
	dis_cmd_1(0x00);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x00);
	setColumn(x+11);
	dis_cmd_1(0x00);
	setColumn(x+12);
	dis_cmd_1(0x00);
	setColumn(x+13);
	dis_cmd_1(0x00);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}		

	void print16(int x)
{
	setColumn(x);
	dis_cmd_1(0x00);
	setColumn(x+1);
	dis_cmd_1(0x00);
	setColumn(x+2);
	dis_cmd_1(0x00);
	setColumn(x+3);
	dis_cmd_1(0xFF);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x3E);
	setColumn(x+6);
	dis_cmd_1(0x49);
	setColumn(x+7);
	dis_cmd_1(0x89);
	setColumn(x+8);
	dis_cmd_1(0x06);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x00);
	setColumn(x+11);
	dis_cmd_1(0x00);
	setColumn(x+12);
	dis_cmd_1(0x00);
	setColumn(x+13);
	dis_cmd_1(0x00);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}	


	void print32(int x)
{
	setColumn(x);
	dis_cmd_1(0x81);
	setColumn(x+1);
	dis_cmd_1(0x91);
	setColumn(x+2);
	dis_cmd_1(0x91);
	setColumn(x+3);
	dis_cmd_1(0x6E);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x6e);
	setColumn(x+6);
	dis_cmd_1(0x89);
	setColumn(x+7);
	dis_cmd_1(0x06);
	setColumn(x+8);
	dis_cmd_1(0x00);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x00);
	setColumn(x+11);
	dis_cmd_1(0x00);
	setColumn(x+12);
	dis_cmd_1(0x00);
	setColumn(x+13);
	dis_cmd_1(0x00);
	setColumn(x+14); //
	dis_cmd_1(0x00);
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}	

	void print64(int x)
{
	setColumn(x);
	dis_cmd_1(0x3E);
	setColumn(x+1);
	dis_cmd_1(0x49);
	setColumn(x+2);
	dis_cmd_1(0x89);
	setColumn(x+3);
	dis_cmd_1(0x06);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0xF0);
	setColumn(x+6);
	dis_cmd_1(0x10);
	setColumn(x+7);
	dis_cmd_1(0x10);
	setColumn(x+8);
	dis_cmd_1(0xFF);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x00);
	setColumn(x+11);
	dis_cmd_1(0x00);
	setColumn(x+12);
	dis_cmd_1(0x00);
	setColumn(x+13);
	dis_cmd_1(0x00);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}		


	void print128(int x)
{
	setColumn(x);
	dis_cmd_1(0x00);
	setColumn(x+1);
	dis_cmd_1(0x00);
	setColumn(x+2);
	dis_cmd_1(0x00);
	setColumn(x+3);
	dis_cmd_1(0xFF);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x43);
	setColumn(x+6);
	dis_cmd_1(0x85);
	setColumn(x+7);
	dis_cmd_1(0x89);
	setColumn(x+8);
	dis_cmd_1(0x71);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x76);
	setColumn(x+11);
	dis_cmd_1(0x89);
	setColumn(x+12);
	dis_cmd_1(0x89);
	setColumn(x+13);
	dis_cmd_1(0x76);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}	

	void print256(int x)
{
	setColumn(x);
	dis_cmd_1(0x43);
	setColumn(x+1);
	dis_cmd_1(0x85);
	setColumn(x+2);
	dis_cmd_1(0x89);
	setColumn(x+3);
	dis_cmd_1(0x71);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0xF2);
	setColumn(x+6);
	dis_cmd_1(0x91);
	setColumn(x+7);
	dis_cmd_1(0x91);
	setColumn(x+8);
	dis_cmd_1(0x8E);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x3E);
	setColumn(x+11);
	dis_cmd_1(0x49);
	setColumn(x+12);
	dis_cmd_1(0x89);
	setColumn(x+13);
	dis_cmd_1(0x06);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}	

	void print512(int x)
{
	setColumn(x);
	dis_cmd_1(0xF2);
	setColumn(x+1);
	dis_cmd_1(0x91);
	setColumn(x+2);
	dis_cmd_1(0x91);
	setColumn(x+3);
	dis_cmd_1(0x8E);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x00);
	setColumn(x+6);
	dis_cmd_1(0x00);
	setColumn(x+7);
	dis_cmd_1(0x00);
	setColumn(x+8);
	dis_cmd_1(0xFF);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x43);
	setColumn(x+11);
	dis_cmd_1(0x85);
	setColumn(x+12);
	dis_cmd_1(0x89);
	setColumn(x+13);
	dis_cmd_1(0x71);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x00);
	setColumn(x+16);
	dis_cmd_1(0x00);
	setColumn(x+17);
	dis_cmd_1(0x00);
	setColumn(x+18);
	dis_cmd_1(0x00);

}	

	void print1024(int x)
{
	setColumn(x);
	dis_cmd_1(0x00);
	setColumn(x+1);
	dis_cmd_1(0x00);
	setColumn(x+2);
	dis_cmd_1(0x00);
	setColumn(x+3);
	dis_cmd_1(0xFF);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x7E);
	setColumn(x+6);
	dis_cmd_1(0x81);
	setColumn(x+7);
	dis_cmd_1(0x81);
	setColumn(x+8);
	dis_cmd_1(0x7E);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0x43);
	setColumn(x+11);
	dis_cmd_1(0x85);
	setColumn(x+12);
	dis_cmd_1(0x89);
	setColumn(x+13);
	dis_cmd_1(0x71);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0xF0);
	setColumn(x+16);
	dis_cmd_1(0x10);
	setColumn(x+17);
	dis_cmd_1(0x10);
	setColumn(x+18);
	dis_cmd_1(0xFF);

}	

	void print2048(int x)
{
	setColumn(x);
	dis_cmd_1(0x43);
	setColumn(x+1);
	dis_cmd_1(0x85);
	setColumn(x+2);
	dis_cmd_1(0x89);
	setColumn(x+3);
	dis_cmd_1(0x71);
	setColumn(x+4);
	dis_cmd_1(0x00); //
	setColumn(x+5);
	dis_cmd_1(0x71);
	setColumn(x+6);
	dis_cmd_1(0x81);
	setColumn(x+7);
	dis_cmd_1(0x81);
	setColumn(x+8);
	dis_cmd_1(0x7E);
	setColumn(x+9);
	dis_cmd_1(0x00); //
	setColumn(x+10);
	dis_cmd_1(0xF0);
	setColumn(x+11);
	dis_cmd_1(0x10);
	setColumn(x+12);
	dis_cmd_1(0x10);
	setColumn(x+13);
	dis_cmd_1(0xFF);
	setColumn(x+14);
	dis_cmd_1(0x00); //
	setColumn(x+15);
	dis_cmd_1(0x76);
	setColumn(x+16);
	dis_cmd_1(0x89);
	setColumn(x+17);
	dis_cmd_1(0x89);
	setColumn(x+18);
	dis_cmd_1(0x76);

}	