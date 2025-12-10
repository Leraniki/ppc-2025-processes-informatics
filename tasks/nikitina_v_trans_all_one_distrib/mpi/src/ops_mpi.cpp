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
  return !GetInput().empty();
}

bool TestTaskMPI::PreProcessingImpl() {
  return true;
}

bool TestTaskMPI::RunImpl() {
  auto input = GetInput();
  auto size = input.size();
  std::vector<int> res(size, 0);

  MPI_Reduce(input.data(), res.data(), size, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  MPI_Bcast(res.data(), size, MPI_INT, 0, MPI_COMM_WORLD);

  GetOutput() = res;
  return true;
}

bool TestTaskMPI::PostProcessingImpl() {
  return true;
}

}  // namespace nikitina_v_trans_all_one_distrib
