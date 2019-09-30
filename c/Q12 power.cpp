/* Function to calculate x raised to the power y */
int power(int x, int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y%2 == 0) 
        return power(x, y/2)*power(x, y/2); 
    else
        return x*power(x, y/2)*power(x, y/2); 
} 
  
/* Program to test function power */
int main() 
{ 
    int x = 2; 
    int y = 3; 
  
    printf("%d", power(x, y)); 
    return 0; 
} 
