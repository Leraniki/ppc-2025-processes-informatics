#include "nikitina_v_trans_all_one_distrib/seq/include/ops_seq.hpp"

namespace nikitina_v_trans_all_one_distrib {

TestTaskSEQ::TestTaskSEQ(const InType &in) {
  SetTypeOfTask(GetStaticTypeOfTask());
  GetInput() = in;
}

bool TestTaskSEQ::ValidationImpl() {
  return !GetInput().empty();
}

bool TestTaskSEQ::PreProcessingImpl() {
  return true;
}

bool TestTaskSEQ::RunImpl() {
  GetOutput() = GetInput();
  return true;
}

bool TestTaskSEQ::PostProcessingImpl() {
  return true;
}

}  // namespace nikitina_v_trans_all_one_distrib
