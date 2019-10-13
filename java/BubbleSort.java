import java.util.*;

class BubbleSort
{
	void sort(int[] ar,int n)
	{
		int j,i,temp;
		for(i=0;i<n-1;i++)
		{			
			for(j=0;j<n-i-1;j++)
			{
				 if(ar[j]>ar[j+1])
				 {
					temp = ar[j];	                                 	
					ar[j]=ar[j+1];
				 	ar[j+1] = temp;
				 }
			}
		}
	}

	static void printarray(int ar[],int n)
	{
		int i;
		System.out.println("The sorted array is :");
		for(i=0;i<n;i++)
		{
			System.out.print(ar[i] + " " );
		}
		System.out.println();
	}
	 

	public static void main(String args[])
	{
		int i;
		Scanner sc = new Scanner(System.in);
		long t1 = System.nanoTime();
		System.out.println("Enter the no. of elements :");
		int n = sc.nextInt();
		int ar[] = new int[n];
		System.out.println("Enter the elements :");
		for(i=0;i<n;i++)
			ar[i] = sc.nextInt();
		BubbleSort ob = new BubbleSort();
		ob.sort(ar,n);
		printarray(ar,n);
		long t2 = System.nanoTime();
		long time = t2-t1;
		System.out.println("Time :" + time);		
		sc.close();
	}
} 
				
