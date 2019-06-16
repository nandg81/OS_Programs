//Program to simulate working of dining philosphers problem
//Author: Nandagopal

import java.util.*;
import java.io.*;
import java.util.concurrent.Semaphore;


class Din
{
	private static Semaphore chopstick[]=new Semaphore[]{
   								new Semaphore(1),
   								new Semaphore(1),
   								new Semaphore(1),
   								new Semaphore(1),
  								new Semaphore(1),
								new Semaphore(1)
							};
	static class Phil extends Thread
	{
		int i;int n;
		Phil(int i,int n)
		{
			this.i=i;
			this.n=n;
		}
        	public void run()
        	{
			for(int j=1;j<=n;j++)
           		{
                		try
                      		{
					chopstick[i].acquire();
					chopstick[(i+1)%5].acquire();
					System.out.println("Philosopher "+i+" is eating");
					Thread.sleep(1000);
					chopstick[i].release();
					chopstick[(i+1)%5].release();
					System.out.println("Philosopher "+i+" is thinking");
					
				}
				catch(Exception e)
                		{
                  			System.out.println("Philospher "+i+" Exception");
                		}
       			}
        	}	
	}
	public static void main(String args[])throws IOException
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the number of times each philosopher should eat");
		int n=Integer.parseInt(in.readLine());
		Phil p1=new Phil(1,n);
		Phil p2=new Phil(2,n);
		Phil p3=new Phil(3,n);
		Phil p4=new Phil(4,n);
		Phil p5=new Phil(5,n);		
		p1.start();		
		p2.start();
        	p3.start();
		p4.start();
        	p5.start();
	}
}
