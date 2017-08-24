#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>

#include <Kokkos_Core.hpp>


typedef Kokkos::View<int*>  int_array;

typedef Kokkos::DefaultExecutionSpace   device_type;

template< typename ExecutionSpace >
struct init_vec {

  int_array v;

  init_vec( int_array vec_in)
    : v( vec_in )
    {
      Kokkos::parallel_for(2,*this);
    }

  KOKKOS_INLINE_FUNCTION
  void operator()( const size_t idx ) const {
    printf("init_vec () index %lu vec(:) %d %d\n", idx, v(0), v(1));
  }
};


int main( int argc, char* argv[] )
{
  Kokkos::initialize( argc, argv );
  printf ("Kokkos default execution space %s\n",
    typeid (Kokkos::DefaultExecutionSpace).name ());

  int_array vec("vec", 2); //proxy for initially empty queue
  typename int_array::HostMirror h_vec = Kokkos::create_mirror_view( vec );
  h_vec(0) = 42;
  Kokkos::deep_copy( vec, h_vec ); //copy the array to the device

  // call the functor to set the first entry of vec to the scalar
  init_vec< device_type > foo(vec);

  Kokkos::finalize();

  return 0;
}
