/* dynamically creates the matrix of size Row_m x Col_n */
#include "lib.h"
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
