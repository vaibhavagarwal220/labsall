#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct sparse
{
	int *sp ;
	int row ;
};

void create_array ( struct sparse * ,int Row_m, int Col_n,int *hist,int *chist) ;
void display ( struct sparse, int Row_m, int Col_n ) ;
int count ( struct sparse ,int Row_m, int Col_n) ;
void create_tuple ( struct sparse *, struct sparse,int Row_m, int Col_n ) ;
void display_tuple ( struct sparse ,int Row_m, int Col_n) ;


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
		printf(" %d \n",chist[i]);
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

/* dynamically creates the matrix of size Row_m x Col_n */
void create_array ( struct sparse *p, int Row_m, int Col_n,int *hist,int *chist)
{
	int n, i ;

	p -> sp = ( int * ) malloc ( Row_m * Col_n * sizeof ( int ) ) ;

	for ( i = 0 ; i < Row_m * Col_n ; i++ )
	{
			printf ( "Enter Sparse Matrix Element No. %d: ", i ) ;
			scanf ( "%d", &n ) ;
			if(n!=0) {

			//printf(" %d \n",hist[i]);
				hist[i%Col_n]++;
			//printf(" %d \n",hist[i]);
			}
			* ( p -> sp + i ) = n ;
	}
	chist[0]=hist[0];
	for ( i = 1; i <Col_n ; i++ )
	{
		chist[i]=hist[i]+chist[i-1];
	}

	printf ( "\n" ) ;

}

/* displays the contents of the matrix */
void display ( struct sparse p, int Row_m, int Col_n )
{
	int i ;

	/* traverses the entire matrix */
	for ( i = 0 ; i < Row_m * Col_n ; i++ )
	{
		/* positions the cursor to the new line for every new row */
		if ( i % Col_n == 0 )
			printf ( "\n" ) ;
		printf ( "%d\t", * ( p.sp + i ) ) ;
	}
	printf ( "\n\n" ) ;
}

/* counts the number of non-zero elements */
int count ( struct sparse p , int Row_m, int Col_n)
{
	int cnt = 0, i ;

	for ( i = 0 ; i < Row_m * Col_n ; i++ )
	{
		if ( * ( p.sp + i ) != 0 )
			cnt++ ;
	}
	return cnt ;
}

/* creates an array that stores information about non-zero elements */
void create_tuple ( struct sparse *p, struct sparse s , int Row_m, int Col_n)
{
	int r = 0 , c = -1, l = -1, i ;

	p -> row = count ( s , Row_m, Col_n) + 1 ;

	p -> sp = ( int * ) malloc ( p -> row * 3 * sizeof ( int ) ) ;

	* ( p -> sp + 0 ) = Row_m ;
	* ( p -> sp + 1 ) = Col_n ;
	* ( p -> sp + 2 ) = p -> row - 1 ;

	l = 2 ;

	for ( i = 0 ; i < Row_m * Col_n ; i++ )
	{
		c++ ;

		/* sets the row and column values */
		if ( ( ( i % Col_n ) == 0 ) && ( i != 0 ) )
		{
			r++ ;
			c = 0 ;
		}

		/* checks for non-zero element
		   row, column and non-zero element value
		   is assigned to the matrix */
		if ( * ( s.sp + i ) != 0 )
		{
			l++ ;
			* ( p -> sp + l ) = r ;
			l++ ;
			* ( p -> sp + l ) = c ;
			l++ ;
			* ( p -> sp + l ) = * ( s.sp + i ) ;
		}
	}
}

/* displays the contents of 3-tuple */
void display_tuple ( struct sparse p, int Row_m, int Col_n )
{
	int i ;

	for ( i = 3 ; i < p.row * 3 ; i++ )//First Tuple carries the information of number of non-zero elements.
	{
		if ( i % 3 == 0 )
			printf ( "\n" ) ;
		printf ( "%d\t", * ( p.sp + i ) ) ;
	}
printf ( "\n" ) ;
}