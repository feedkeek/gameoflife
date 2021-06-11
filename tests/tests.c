#include <CUnit/CUnit.h>
#include "../game/game.h"

// void test_new_board(){
//   Cell *board = new_board(10);

//   CU
// }

void test_get_cell(){
  CU_ASSERT(0 == 0);
}

int main()
{
  // Initialize CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  // Add suite1 to registry
  CU_pSuite pSuite1 = CU_add_suite("Test_Suite", 0, 0);
  if (0 == pSuite1)
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((0 == CU_add_test(pSuite1, "\n\n……… Testing get_cell function.\n\n", test_get_cell)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
}