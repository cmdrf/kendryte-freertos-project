/* Wrapper to match function signatures of the external interrupt handler.

Not sure if this is really necessary, since the assembler doesn't care much
about C function signatures anyway. handle_irq_m_ext() even has two different
signatures in the SDK. */

#include <stdint.h>
#include <stddef.h>

extern uintptr_t handle_irq_m_ext(uintptr_t cause, uintptr_t epc, uintptr_t regs[32], uintptr_t fregs[32]);

void external_interrupt_handler( uint32_t cause )
{
	// handle_irq_m_ext doesn't do anything with the other parameters anyway
	handle_irq_m_ext(cause, 0, NULL, NULL);
}
