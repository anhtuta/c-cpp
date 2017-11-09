int scandigits(float* x,int div){
	
	register int c = getchar();
	register float pow10 = 1;
	if(x == NULL) return -1;
	*x = 0;
	while((c<'0'||c>'9')&&c!='-'){
		c=getchar();
	}
	if(c == '-'){
		neg = 1;
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		*x *= 10;
		*x += (c-'0');
		pow10*= 10;
		c = getchar();
	}
	if(neg) *x = -*x;
	if(div) *x /= pow10;
	return c;
}

void scanfloat(float *x){
	float left,right = 0;
	if (x == NULL){
		return;
	}
	neg = 0;
	int ret = scandigits(&left,0);
	if(ret == '.') scandigits(&right,1);
	*x = left + right;
}