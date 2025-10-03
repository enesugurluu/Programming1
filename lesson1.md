#Programming 1 Codes


##Basic Data Types
•
Data types are declarations for variablesthat determines the type and size of data associated with variables
•
For example,
int myVar;
•
Here, myVar is a variable of int (integer) typeand the size of int is 4 bytes


###intdata type
•
Integers are whole numbers that can have both zero, positive and negative values (0, -23, 985) but no decimal values
•
We can use int for declaring an integer variable
•
The size of int is usually 4 bytes (32 bits)
•
It can take 232 distinct states from -2147483648 to 2147483647


###floatanddoubledata types
•
float and double are used to hold real numbers
float salary=0.657;
double price=12.35;
•
What's the difference between float and double?
•
The size of float (single precision float data type) is 4 bytes
•
The size of double (double precision float data type) is 8 bytes


###chardata type
•
Used for declaring character type variables. For example,
char test = 'h’;
•
The size of the character variable is 1 byte.


###short and longdata types
•
If you need to use a large number, you can use longspecifier(pleasenotethatthe size of "long" data type is not fixed unlike other data types. Itvaries from architectures, operating system and even withcompiler that we are using, seehttps://www.geeksforgeeks.org/cpp/need-long-data-type-c-cpp/)
long a;
long long b;
long double c;
•
Here variables a and b can store integer values, and c can store a floating-point number
•
If you are sure, only a small integer ([−32767, +32767] range) will be used, you can use short
short d;

###voiddata type
•
void is an incomplete type,and it means nothing or no type
•
You can think of void as absentand you cannot create variables of void type
•
For example, if a function is not returning anything, its return type should be void


##Real-World Uses of C Data Types
•
###short (−32,767 … +32,767)
•
Thermometer readings (−100 … +100 °C)
•
Heart rate (30 … 250 BPM)
•
Elevator floors (< 1000)
•
###int (commonly −2,147,483,648 … +2,147,483,647 on 32-bit/64-bit systems)
•
Population of a country (~1.4 billion max)
•
###unsignedvariants
•
unsignedshort(0 … 65,535): deviceIDs, port numbers, studentIds
•
###char (−128 … +127 or 0 … 255 if unsigned)
•
Single characters in text
•
Small numeric values (like age in years, 0 … 120)
•
Flags or status codes (0 = off, 1 = on, etc.)
•
###Floating-point types
•
float: approximate real numbers, sensor values like temperature with decimals (36.5 °C)
•
double: precise calculations, physics simulations, financial interest rates