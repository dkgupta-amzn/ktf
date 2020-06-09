#ifndef KTF_PERCPU_H
#define KTF_PERCPU_H

#include <ktf.h>
#include <lib.h>
#include <list.h>
#include <page.h>

struct percpu {
    list_head_t list;
    unsigned int id:8, apic_id:8, enabled:1, bsp:1, family:4, model:4, stepping:4;

    idt_entry_t *idt __aligned(16);
    idt_ptr_t idt_ptr;

    gdt_desc_t gdt[NR_GDT_ENTRIES] __aligned(16);
    gdt_ptr_t gdt_ptr;

    x86_tss_t tss __aligned(16);
#if defined(__i386__)
    x86_tss_t tss_df __aligned(16);
#endif
} __aligned(PAGE_SIZE);
typedef struct percpu percpu_t;

/* External declarations */

extern void init_percpu(void);
extern percpu_t *get_percpu_page(unsigned int cpu);

#endif /* KTF_PERCPU_H */