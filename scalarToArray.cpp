#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>

#include <Kokkos_Core.hpp>


typedef Kokkos::View<int*>  int_array;
typedef Kokkos::View<int>   int_type;

typedef Kokkos::DefaultExecutionSpace   device_type;

template< typename ExecutionSpace >
struct init_vec {

  int_type var;
  int_array vec;

  init_vec( int_type var_in, int_array vec_in)
    : var( var_in )
    , vec( vec_in )
    {
      Kokkos::parallel_for(2,*this);
    }

  KOKKOS_INLINE_FUNCTION
  void operator()( const size_t idx ) const {
    printf("init_vec () index %lu vec(:) %d %d\n", idx, vec(0), vec(1));
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

  int_type var("var", 1); //proxy for BFS root node
  typename int_type::HostMirror h_var = Kokkos::create_mirror_view( var );
  h_var() = 42;
  Kokkos::deep_copy( var, h_var ); //copy the scalar to the device

  // call the functor to set the first entry of vec to the scalar
  init_vec<device_type>(var, vec);

  Kokkos::finalize();

  return 0;
}
