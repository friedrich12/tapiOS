volatile unsigned char* video = (unsigned char*)0xB8000;

static unsigned char row=0;
static unsigned char line=0;

void printk(const char* str)
{
	const char* s;
	for(s=str; *s; s++)
	{
		char c=*s;
		if(c=='\n')
		{
			row=0;
			line++;
			continue;
		}
		*(video+(line*0xA0)+row)=c;
		*(video+(line*0xA0)+row+1)=0x07; // Gray on black
		row+=2;
		if(row>=0xA0)
		{
			row=0;
			line++;
		}
	}
}

void kmain(unsigned long magic, unsigned long addr)
{
	printk("Welcome to tapiOS!\n");
	printk("You will be able to do...nothing!\n");
}
