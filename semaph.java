//Program to implement producer consumer problem using semaphore
//Author: Nandagopal

import java.util.*;
import java.util.concurrent.Semaphore;


class semaph
{
	private static final int BUFFER_SIZE=5;
	private static Semaphore empty=new Semaphore(BUFFER_SIZE);
	private static Semaphore full=new Semaphore(0);
	private static Semaphore mutex=new Semaphore(1);
	private static int count=0;
	static class Producer extends Thread
	{
        	public void run()
        	{
			for(int i=1;i<=5;i++)
           		{
                		try
                      		{
					System.out.println("Producer produced item: "+i);
                        		empty.acquire();
                    			mutex.acquire();
                    			System.out.println("Item "+i+" placed in buffer");
                    			Thread.sleep(1000);
					mutex.release();
					full.release();
				}
				catch(Exception e)
                		{
                  			System.out.println("Producer Exception");
                		}
       			}
        	}	
	}
	static class Consumer extends Thread
	{
		public void run()
        	{
			for(int i=1;i<=5;i++)
			{
				try
                		{
					full.acquire();
                    			mutex.acquire();
					System.out.println("Item "+i+" removed from buffer");
                    			Thread.sleep(1000);
					mutex.release();
					empty.release();
					System.out.println("Consumer consumed item: "+i);
				}
				catch(Exception e)
                		{
                			System.out.println("Consumer Exception");
                		}
			}

        	}
   	}
	public static void main(String args[])
	{
		Producer p=new Producer();
		Consumer c=new Consumer();
		p.start();
        	c.start();
	}
}
