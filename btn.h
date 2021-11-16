//This is code that was reused from our knob lab which was originally given to us by Dr.Carrol.
// Defines the structs used btn.c 
#include "stm32l053xx.h"
#include <stdint.h>
enum btn_status{UP, DOWN, MAYBE_PRESSED, MAYBE_RELEASED};

enum btn_level {BTN_ACTIVE, BTN_INACTIVE};

enum btn_edge {ACTIVE, INACTIVE, ACTIVATING_EDGE, DEACTIVATING_EDGE};

struct btn_struct{uint32_t mask_for_btn; 
                  volatile uint32_t *pin_ptr; 
                  enum btn_status state;};

void init_btn(uint32_t mask_for_btn, 
              volatile uint32_t *pin_ptr, 
              struct btn_struct *pb);

enum btn_level read_btn(struct btn_struct *pb);
 
enum btn_edge update_btn(struct btn_struct *pb);
