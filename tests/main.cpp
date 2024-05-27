
#include <fmt/format.h>

#include "synapse/status.h"
#include "synapse/node.h"
#include "synapse/signal_chain.h"
#include "synapse/synapse.h"
#include "synapse/device.h"

int main()
{
  int i = 0;
  i++;
  fmt::println("hi! i = {}", i);
  return i;
}
