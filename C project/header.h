void create();
void bill();
void display();
void edit();
void invoice();
void mdelete();
void mdisplay();

void registerUser(char f[]);
void csearch(char b[]);

struct item
{
	int productno;
	char productname[10];
	int quantity;
	int price;
}
item;
struct customer
{
	int productno;
	char productname[10];
	int quantity;
	int price;
	int amount;
}
cst[100];
struct temporary
{
	int productno;
	char productname[10];
	int quantity;
	int price;
	int amount;
}
cstr[100];

struct customer_details{
	char customer_name[50];
	char customer_phno[11];
	char address[100];
};
