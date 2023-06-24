
typedef void (*canIsr_t)(void);

typedef struct
{
  uint32_t ID :29;
  bool rtr;
  uint8_t dlc :3;
  uint8_t data[8];
  canIsr_t canIsr;
}canHandler_t; 

void canInit();
void canRead();
void canWrite();
void canIsr();