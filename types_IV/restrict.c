
// you never have to use this BUT:
// if you use this correctly you will realize some performance gain
// and if you don't, expect undefined behavior 

// restrict, is a hint to the compiler that a particular piece of memory 
// will only be accessed by one pointer and never by another.

// If a developer declares a pointer to be restrict and then access the object it 
// points to using another way (like using another pointer to it), the behaviour 
// is undefined.


void swap (int* restrict a, int* restrict b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main(void) {

	int x =  10, y = 20;
	swap(&x, &y);
	swap(&x, &x);	// undefined behaviour cause a,b point to the same place in memory
			// and they are restricted 
}


