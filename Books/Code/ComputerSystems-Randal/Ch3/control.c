/* compile with -O1 to analize the assembly code  */
int asm_if(int x){
	if (x>0)
		x+=4;
	else
		x--;
	return x;	
}

void asm_while(int x){
	while(x){
		x--;
	}
}

void asm_for(int x){
	int y = x;
	for(int i=0; i<x; i++)
		y+=x;
}

int asm_switch(int x){
	
	switch(x){
		case 1:
			x++;
			break;
		case 2:
			x--;
			break;
		case 3:
			x*=5;
			break;
		case 4:
			x+=10;
                        break;
                case 5:
                        x-=10;
                        break;
		default:
			x*=2;
	}

	return x;
}

/* when switch is small it will be encoded as multiple do-while */
int short_switch( int x){	
	switch(x){
		case 1:
			x++;
			break;
		case 2:
			x--;
			break;
		default:
			x*=2;
	}

	return x;
}


int short_if( int x){	
    if (x==1)
        x++;
    else if (x==2)
        x--;
    else
        x*=2;

    return x;
}
