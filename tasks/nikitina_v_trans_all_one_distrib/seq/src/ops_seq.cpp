#include "nikitina_v_trans_all_one_distrib/seq/include/ops_seq.hpp"

namespace nikitina_v_trans_all_one_distrib {

TestTaskSEQ::TestTaskSEQ(const InType &in) {
  SetTypeOfTask(GetStaticTypeOfTask());
  GetInput() = in;
}

bool TestTaskSEQ::ValidationImpl() {
  return true;
}

bool TestTaskSEQ::PreProcessingImpl() {
  return true;
}

bool TestTaskSEQ::RunImpl() {
  unsigned int size = GetInput().size();

  if (size == 0) {
    return true;
  }

  GetOutput() = GetInput();
  return true;
}

bool TestTaskSEQ::PostProcessingImpl() {
  return true;
}

}  // namespace nikitina_v_trans_all_one_distrib
