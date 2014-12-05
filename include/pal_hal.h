/*
 * Hardware Abstraction Library
 */

/*initialize device at beginning of program, get information from device tree, imagine multiple hetero devices*/
pal_dev_t pal_init( int flags );

/*open a device/connection, one "core" at a time, open core for ARM as well, use the pal_dev_t as the */
/*this sends down the physical address to that core, containing the pointer to the pal_dev_t*/
/*wrap some foor loops around this*/
int pal_open( pal_dev_t dev, int cpu, int flags );

/*malloc, returns a virtual pointer within the dev processors space, can allocate memory remotely*/
void *pal_malloc( pal_dev_t dev, int cpu, size_t size, int flags );//arguments??

/*free*/
void pal_free( pal_dev_t dev, pal_mem_t mem );

/*load a program into memory*/
int pal_readelf( pal_dev_t dev, char* src, size_t len, char* opt, char** log);

/*get a symbol from elf*/
pal_sym_t pal_getsymbol( pal_program_t prg, const char* symbol );

/*load and execute a program on one cpu*/
int pal_load( pal_dev_t dev, int cpu, pal_kernel_t krn, unsigned int narg, void** args);

/*load and execute program on all open CPUs "broadcast to workgroup"*/
int pal_loadgroup( pal_dev_t dev, pal_kernel_t krn, unsigned int narg, void** args);

/*memcpy from cpu0 to cpu1, most of them should use some kind of hw opt like DMA*/
size_t *pal_memcpy( pal_dev_t dev, int cpu0, int cpu1, void *str0, const void *str1, size_t n, int flags );

/*close a device/connection, one "core at a time"*/
int pal_close( pal_dev_t, int n, int flags );

/*shut down the device at end of program*/
pal_dev_t pal_shutdown();

/* interact with one of n timers */
void pal_counter_set(int n, unsigned int val);
void pal_counter_get(int n);
void pal_counter_start(int n, pal_timer_config_t);
void pal_counter_stop(int n);

/*signal function..need to rethink this one...*/
void pal_signal(e_epiphany_t *dev, int cpu);







		      						      


