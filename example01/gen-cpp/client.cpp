//#include <stdio.h>

#include <iostream>
#include <stdlib.h>

#include  "Calcu.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include <vector>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using namespace std;



int main(int argc,char **argv){

	::apache::thrift::stdcxx::shared_ptr<TSocket> socket (new TSocket("192.168.101.18",9090));
	::apache::thrift::stdcxx::shared_ptr<TTransport> transport (new TBufferedTransport(socket));
	::apache::thrift::stdcxx::shared_ptr<TProtocol> protocol (new TBinaryProtocol(transport));
	CalcuClient client(protocol);
	
	transport->open();

	int n,ret;
	double b,b2;
	vector<double> a(1);
	
	while(1)
	{
		system("clear");
	       
		ret=1;
		printf("this is a simple add-program for array:\n");
		printf("size of the array(please input an int num):\n");
		ret=scanf("%d",&n);
		getchar();
		if(0==ret)
		{
			printf("input err!");
			break;

		}
		//a.resize(n);
		
		ret=1;
		
		printf("memb of array(end with the Enter):\n");
		
		for(int m=n;m>0;)
		{
			ret=1;
			ret=scanf("%lf",&b);
			getchar();
			if(0==ret)
			{
				printf("input err! please try again:\n");
				a.clear();
			}
			if(0!=ret)
			{
				a.push_back(b);
				m=m-1;
			}
			
		}
		printf("after add:\n");
		for(int m=1;m<=n;)
		{
			b2=a[m];
			b2=client.add(b2);
			printf("%10.3lf",b2);
			m++;
		}
		putchar('\n');
		printf("press Enter to continue");
		getchar();
		
		/*for(vector<double>::iterator tmp = a2.begin();tmp!= a2.end();tmp++)
		{
			cout<<*tmp<<endl;
		}*/
	}
	transport->close();
	return 0;
}
