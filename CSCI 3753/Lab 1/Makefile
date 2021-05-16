obj-$(CONFIG_EISA)              += eisa.o
obj-$(CONFIG_PCSPKR_PLATFORM)   += pcspeaker.o

obj-$(CONFIG_X86_CHECK_BIOS_CORRUPTION) += check.o

obj-$(CONFIG_SWIOTLB)                   += pci-swiotlb.o
obj-$(CONFIG_OF)                        += devicetree.o
obj-$(CONFIG_UPROBES)                   += uprobes.o
obj-y                                   += sysfb.o
obj-$(CONFIG_X86_SYSFB)                 += sysfb_simplefb.o
obj-$(CONFIG_EFI)                       += sysfb_efi.o

obj-$(CONFIG_PERF_EVENTS)               += perf_regs.o
obj-$(CONFIG_TRACING)                   += tracepoint.o
obj-$(CONFIG_SCHED_MC_PRIO)             += itmt.o
obj-$(CONFIG_X86_INTEL_UMIP)            += umip.o

obj-$(CONFIG_UNWINDER_ORC)              += unwind_orc.o
obj-$(CONFIG_UNWINDER_FRAME_POINTER)    += unwind_frame.o
obj-$(CONFIG_UNWINDER_GUESS)            += unwind_guess.o

obj-y					+= helloworld.o
obj-y					+= Simple_add.o

###
# 64 bit specific files
ifeq ($(CONFIG_X86_64),y)
        obj-$(CONFIG_AUDIT)             += audit_64.o

        obj-$(CONFIG_GART_IOMMU)        += amd_gart_64.o aperture_64.o
        obj-$(CONFIG_CALGARY_IOMMU)     += pci-calgary_64.o tce_64.o

        obj-$(CONFIG_PCI_MMCONFIG)      += mmconf-fam10h_64.o
        obj-y                           += vsmp_64.o

endif
                                              149,0-1       Bot

