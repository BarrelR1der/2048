void setColumn(int t){                                       //done 
	int x = 0;
	while (x != t) 
	{
		x++;
	}
			volatile uint32_t lsb = t & 0x0F;
			volatile uint32_t msb = ((t & 0xF0) >> 4) | 0x10;            //checks all the columns for the matching column we choose
	//finds the bits to be sent for msb and lsb
	

	
	
	dis_cmd_0(lsb);
	dis_cmd_0(msb);                                      //sets the column address based on msb and lsb
	
}


void setPage(){                                         //done
	//uint32_t P = page_adr();
	volatile uint32_t pagecmd; 
	
	pagecmd = P | 0xB0;                                  //finds bits for page address
	
	dis_cmd_0(pagecmd);                                   //sets the page address
	
	
}


// Anchor Bits
// 3,0 27,0 51,0 75,0
// 3,2 27,2 51,2 75,2
// 3,4 27,4 51,4 75,4
// 3,6 27,6 51,6 75,6









void print2(int x, int y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); //
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80);
	setColumn(x+7);
	dis_cmd_1(0x80);
	setColumn(x+8);
	dis_cmd_1(0x80);
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x84);
	setColumn(x+11);
	dis_cmd_1(0x88);
	setColumn(x+12);
	dis_cmd_1(0x88);
	setColumn(x+13);
	dis_cmd_1(0x87);
	setColumn(x+14);
	dis_cmd_1(0x80); //
	setColumn(x+15);
	dis_cmd_1(0x80);
	setColumn(x+16);
	dis_cmd_1(0x80);
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	SetPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); //
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01);
	setColumn(x+7);
	dis_cmd_1(0x01);
	setColumn(x+8);
	dis_cmd_1(0x01);
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0x31);
	setColumn(x+11);
	dis_cmd_1(0x51);
	setColumn(x+12);
	dis_cmd_1(0x91);
	setColumn(x+13);
	dis_cmd_1(0x11);
	setColumn(x+14);
	dis_cmd_1(0x01); //
	setColumn(x+15);
	dis_cmd_1(0x01);
	setColumn(x+16);
	dis_cmd_1(0x01);
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
}	
	
void print4(int x, int y)
{
	setPage(y);

	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x80);
	setColumn(x+2);
	dis_cmd_1(0x80);
	setColumn(x+3);
	dis_cmd_1(0x80);
	setColumn(x+4);
	dis_cmd_1(0x80); //
	setColumn(x+5);
	dis_cmd_1(0x80);
	setColumn(x+6);
	dis_cmd_1(0x80);
	setColumn(x+7);
	dis_cmd_1(0x80);
	setColumn(x+8);
	dis_cmd_1(0x80);
	setColumn(x+9);
	dis_cmd_1(0x80); //
	setColumn(x+10);
	dis_cmd_1(0x8F);
	setColumn(x+11);
	dis_cmd_1(0x88);
	setColumn(x+12);
	dis_cmd_1(0x88);
	setColumn(x+13);
	dis_cmd_1(0x87);
	setColumn(x+14);
	dis_cmd_1(0x80); //
	setColumn(x+15);
	dis_cmd_1(0x80);
	setColumn(x+16);
	dis_cmd_1(0x80);
	setColumn(x+17);
	dis_cmd_1(0x80);
	setColumn(x+18);
	dis_cmd_1(0x80);
	setColumn(x+19);
	dis_cmd_1(0x80);
	setColumn(x+20);
	dis_cmd_1(0x80);
	setColumn(x+21);
	dis_cmd_1(0x80);
	setColumn(x+22);
	dis_cmd_1(0x80);
	setColumn(x+23);
	dis_cmd_1(0xFF);
	
	SetPage(y+1);
	
	setColumn(x);
	dis_cmd_1(0xFF);
	setColumn(x+1);
	dis_cmd_1(0x01);
	setColumn(x+2);
	dis_cmd_1(0x01);
	setColumn(x+3);
	dis_cmd_1(0x01);
	setColumn(x+4);
	dis_cmd_1(0x01); //
	setColumn(x+5);
	dis_cmd_1(0x01);
	setColumn(x+6);
	dis_cmd_1(0x01);
	setColumn(x+7);
	dis_cmd_1(0x01);
	setColumn(x+8);
	dis_cmd_1(0x01);
	setColumn(x+9);
	dis_cmd_1(0x01); //
	setColumn(x+10);
	dis_cmd_1(0x31);
	setColumn(x+11);
	dis_cmd_1(0x51);
	setColumn(x+12);
	dis_cmd_1(0x91);
	setColumn(x+13);
	dis_cmd_1(0x11);
	setColumn(x+14);
	dis_cmd_1(0x01); //
	setColumn(x+15);
	dis_cmd_1(0x01);
	setColumn(x+16);
	dis_cmd_1(0x01);
	setColumn(x+17);
	dis_cmd_1(0x01);
	setColumn(x+18);
	dis_cmd_1(0x01);
	setColumn(x+19);
	dis_cmd_1(0x01);
	setColumn(x+20);
	dis_cmd_1(0x01);
	setColumn(x+21);
	dis_cmd_1(0x01);
	setColumn(x+22);
	dis_cmd_1(0x01);
	setColumn(x+23);
	dis_cmd_1(0xFF);
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