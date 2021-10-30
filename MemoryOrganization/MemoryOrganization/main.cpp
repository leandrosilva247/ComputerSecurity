#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char * passMessage = ":)";
const char * failMessage = ":(";

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
   char text[8] = "*MAIN**";
   long number = 123456;
   void (*pointerFunction)() = fail;
   const char * message = failMessage;

   // display the initial values of the local variables
   cout << "main() : " << (void *)main << endl;
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   // call the other functions
   one(number + 111111);     // 234567

   // display the new values of the local variables
   cout << "main() - after\n";
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   return 0;
}

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char * p)
{
   string output;
   for (int i = 0; i < 8; i++)
	   output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/************************************************
 * CONVERT TO HEX
 * Convert the data from the memory location
 * to a hex.  This helps to see the address segments
 ***********************************************/
void toHex(char * hex, long * address)
{
   sprintf(hex, "0x%lx", *(address) );
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number)               // 234567
{
   char text[8] = "**ONE**";

   cout << "one() : " << (void *)one << endl;
   cout << "\tmessage: " << (void *)failMessage << endl;
   cout << "\tfail():  " << (void *)fail        << endl;

   two(number + 111111);    // 345678
}



/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number)              // 345678
{
   // start your display of the stack from this point
   long bow = number + 111111;     // 456789
   char text[8] = "**TWO**";
   long * pLong = NULL;
   char * pChar = NULL;

   // header for our table. Use these setw() offsets in your table
   cout << '[' << setw(2) << 'i' << ']'
		<< setw(15) << "address"
		<< setw(20) << "hexadecimal"
		<< setw(20) << "decimal"
		<< setw(18) << "characters"
		<< endl;
   cout << "----+"
		<< "---------------+"
		<< "-------------------+"
		<< "-------------------+"
		<< "-----------------+\n";
   for (long i = 24; i >= -4; i--)   // You may need to change 24 to another number
   {
	  long * address = &bow + i;
	  char hexadecimal[20];
	  toHex(hexadecimal, address);
	  long long decimal = *(address);
	  string characters = displayCharArray((char *)(address));
	  	  
	  cout 	<< '[' << setw(2) << i << ']'
			<< setw(15) << address
			<< setw(20) << hexadecimal
			<< setw(20) << decimal
			<< setw(20) << characters
			<< "\n";
   }

   ////////////////////////////////////////////////
   // Insert code here to change the variables in main()
																				
   // change text in main() to "*main**"

   // change number in main() to 654321

   // change pointerFunction in main() to point to pass

   // change message in main() to point to passMessage

   //
   ////////////////////////////////////////////////
	
	
   
   pChar = (char * ) & bow;
   while (string(pChar++) != "*MAIN**");   //check before moving
   std::cout << pChar << (void * ) pChar << std::endl;

   // change text in main() to "*main**"
   pChar[0] = 'm';
   pChar[1] = 'a';
   pChar[2] = 'i';
   pChar[3] = 'n';

   std::cout << pChar << std::endl;  //show main

   pLong = (long * ) & bow;
   while ( * pLong != 123456) {    //check before moving
     pLong++; //count pLong
   }
   std::cout << * pLong << std::endl;
   * pLong = 654321; // change number in main() to 654321
   std::cout << * pLong << std::endl; //show 654321

   pLong = (long * ) & bow;
   while ( * pLong != (long long) fail) {
     pLong++;
   }
   std::cout << * pLong << std::endl;
   * pLong = (long long) pass;
   // change pointerFunction in main() to point to pass

   std::cout << * pLong << std::endl;
   // change message in main() to point to passMessage

   pLong = (long * ) & bow;
   while ( * pLong != (long long) failMessage) {
     pLong++;
   }
   
   pChar = (char * ) * pLong;
   std::cout << string(pChar) << std::endl;
   * pLong = (long long) passMessage;
   
   pChar = (char * ) * pLong;
   std::cout << string(pChar) << std::endl;


   }	
}
