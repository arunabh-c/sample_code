#ifndef DEVICE_FILE_H_
#define DEVICE_FILE_H_
#include <linux/compiler.h> /* __must_check */

//__must_check is defined as: #define __must_check __attribute__((warn_unused_result))
//The warn_unused_result attribute causes a warning to be emitted if a caller of the 
//function with this attribute does not use its return value. This is useful for 
//functions where not checking the result is either a security problem or always a bug,
//such as realloc.
__must_check int register_device(void); /* 0 if Ok*/
void unregister_device(void);

#endif //DEVICE_FILE_H_
