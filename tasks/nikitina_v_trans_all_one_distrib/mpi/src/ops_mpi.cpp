#include "nikitina_v_trans_all_one_distrib/mpi/include/ops_mpi.hpp"

#include <mpi.h>

#include <algorithm>
#include <vector>

namespace nikitina_v_trans_all_one_distrib {

TestTaskMPI::TestTaskMPI(const InType &in) {
  SetTypeOfTask(GetStaticTypeOfTask());
  GetInput() = in;
}

bool TestTaskMPI::ValidationImpl() {
  return true;
}

bool TestTaskMPI::PreProcessingImpl() {
  return true;
}

bool TestTaskMPI::RunImpl() {
  unsigned int size = GetInput().size();

  if (size == 0) {
    return true;
  }

  GetOutput().resize(size);

  MPI_Reduce(GetInput().data(), GetOutput().data(), size, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  MPI_Bcast(GetOutput().data(), GetOutput().size(), MPI_INT, 0, MPI_COMM_WORLD);

  return true;
}

bool TestTaskMPI::PostProcessingImpl() {
  return true;
}

}  // namespace nikitina_v_trans_all_one_distrib
