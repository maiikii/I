
int logBase10Estimate(int n)
{
	int x;
	if(n<10)
		return 0;
	
}

int floor(float x)
{
	int n=x;
	return n;
}

int ceiling(float x)
{
	int n=x;
	return n;
}

int isAlNum(char ch)
{
	if( (ch>='0' && ch<='9') || (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') )
		return 1;
	return 0;
}

int isAlpha(char ch)
{
	if( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') )
		return 1;
	return 0;
}

int isUpper(char ch)
{
	if(ch>='A' && ch<='Z')
		return 1;
	return 0;
}

int isLower(char ch)
{
	if(ch>='a' && ch<='z')
		return 1;
	return 0;
}

char toUpper(char ch)
{
	if(ch>='a' && ch<='z')
		return ch-32;
	return ch;
}

char toLower(char ch)
{
	if(ch>='A' && ch<='Z')
		return ch+32;
	return ch;
}

int isPunctuation(char ch)
{
	if( ch=='!' || ch==34 || (ch>38 && ch<')') || (ch>'+' && ch<'/') || ch==':' || ch==';' || ch=='?' || ch=='[' || ch==']' || ch=='{' || ch=='}')
		return 1;
	return 0;
}

int toInteger(char st[])
{
	int ret=0, i=0, rem, x;
	for(; st[i]!='\0'; i++)
		ret=ret*10+(st[i]-'0');
	return ret;
}

float toFloat(char st[])
{
	int i=0;
	float ret=0, dec=0, x=.10;
	for(; st[i]!='.' && st[i]!='\0'; i++)
		ret=ret*10+(st[i]-'0');
	for(dec=1, i+=1; st[i]!='\0'; i++){
		dec=dec*x+(st[i]-'0');
		x=x/10;
	}
	return ret+dec;
}

int abs(int x)
{
	if(x<0)
		return x*-1;
	return x;
}

void stringCopy(char src[], char dest[])
{
	int i=0;
	for(; src[i]!='\0'; i++)
		dest[i]=src[i];
}

int substring(char s1[], char s2[])
{
	int i=0, c, sf=0, st=0;
	for(; s2[i]!='\0'; i++){
		for(; s1[i]!='\0'; c++){
			if(isUpper(s2[i]))
				s2[i]+=32;
			if(isUpper(s1[i]))
				s1[i]+=32;
			if(s2[i]==s1[c]){
				sf=1;
				break;
			}
		}
		if(sf){
			if(s2[i+1]!=s1[c+1]){
				st=1;
				break;
			}
		}
	}
	if(st && s2[i+1]!='\0')
		return 0;
	return 1;
}

int stringCompare(char s1[], char s2[])
{
	int i=0;
	for(; s1[i]!='\0' && s2[i]!='\0'; i++){
		if(isUpper(s2[i]))
			s2[i]+=32;
		if(isUpper(s1[i]))
			s1[i]+=32;
		if(s1[i]!=s2[i])
			if(s1[i]<s2[i])
				return -1;
			else
				return 1;
	}
	return 0;
}

void camelCase(char st[])
{
	int i, x;
	for(i=0; st[i]!=0; i++);
	for(x=0; x<i; x++){
		if(x==i/2)
			if(st[i]>='a')
				printf("%c", st[i]-32);
			else
				printf("%c", st[i]);
		else
			if(st[i]>='A')
				printf("%c", st[i]+32);
			else
				printf("%c", st[i]);
	}
		
}

void Reverse(char st[])
{
	int i=0, len, x;
	for(len=0; st[len]!='\0'; len++);
	x=len/2;
	printf("\n%d", len);
	for(len-=1; i<=x; i++, len--){
		printf("\n%c %c", st[i], st[len]);
		st[i]=st[i]+st[len];
		printf("\n%c ", st[i]);
		st[len]=st[len]-st[i];
		printf("%c ", st[len]);
		st[i]=st[i]-st[len];
		printf("%c", st[i]);
	}
}

int humbleNumber(int x)
{
	int cf=2, n, pf;
	if(x>0 && x<11)
		return 1;
	for(n=2; n<=x; n++){
		cf=2;
		pf=1;
		while(cf*cf<=n){
			if(n%cf==0){
				pf=0;
				break;
			}
			cf++;
		}
		if(pf)
			if(x%n==0)
				if(n>7)
					return 0;
	}
	return 1;
}

int reverse(int x)
{
	int ret=0, rem;
	while(x>0){
		rem=x%10;
		ret=ret*10+rem;
		x/=10;
	}
	return ret;
}

