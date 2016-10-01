#include "lib.h"
int main(int argc, char* argv[])
{
	struct sparse s1, s2 ,s3;
	int c ,i;
	int Row_m;
	int Col_n;
	if(argc != 3)
 	{
		printf("Usage: Requires two parameters \n \t[a] No of Rows,\n \t[b] No of Columns\n");
		exit(0);
	}
	Row_m=atoi(argv[1]);
	Col_n=atoi(argv[2]);
	int hist[Col_n],chist[Col_n],pos[Col_n];
	for ( i = 0 ; i <Col_n ; i++ )
	{
		hist[i]=0;
		pos[i]=0;
	}

	printf ( "Please Input the Sparse Matrix element by element : \n") ;
	create_array ( &s1 ,Row_m, Col_n, hist,chist) ;
	printf ( "The Input Sparse Matrix with %d Non-Zero Element is Displayed Below : \n", count ( s1 ,Row_m, Col_n)) ;
	display ( s1 ,Row_m, Col_n) ;
	create_tuple ( &s2, s1, Row_m, Col_n ) ;
	printf ( "Sparse Representation of Non-Zero Elements (in 3-tuple form): \n" ) ;
	display_tuple ( s2 ,Row_m, Col_n ) ;
	//for ( i = 0 ; i <Col_n ; i++ )
	//{/
		//printf(" %d \n",chist[i]);
	//}
	{
		int l , i ;

	s3.row = count ( s1 , Row_m, Col_n) + 1 ;

	s3.sp = ( int * ) malloc ( s2.row * 3 * sizeof ( int ) ) ;

	* ( s3.sp + 0 ) = Row_m ;
	* ( s3.sp + 1 ) = Col_n ;
	* ( s3.sp + 2 ) = s3.row - 1 ;
	//printf(" %d %d %d \n",* ( s3.sp ),* ( s3.sp + 1 ),* ( s3.sp + 2 ));
	 

	for ( i = 1 ; i < s3.row  ; i++ )
	{	
			
			l=(*(s2.sp+ 3*(i)+1)!=0)?(3*(chist[*(s2.sp+ 3*(i) + 1) - 1] + pos[*(s2.sp+ 3*i + 1)]) + 3)
			:(3*(1+pos[*(s2.sp+ 3*i + 1)]));
			
			//printf("Location: %d %d %d %d Pos:%d\n",l/3,*(s2.sp+ 3*i + 1),*(s2.sp+ 3*i + 0),*(s2.sp+ 3*i + 2),pos[*(s2.sp+ 3*i + 1)]);
			pos[*(s2.sp+ 3*i + 1)]++;
			* (s3.sp + l ) = *(s2.sp+ 3*i + 1);
			l++ ;
			* (s3.sp + l ) = *(s2.sp+ 3*i) ;
			l++ ;
			* (s3.sp + l ) = * (s2.sp+ 3*i + 2) ;
		
	}
	printf("Transpose of given sparse matrix in tuple form:\n");
	display_tuple(s3,Row_m,Col_n);
	}
	
	return 0 ;
}


