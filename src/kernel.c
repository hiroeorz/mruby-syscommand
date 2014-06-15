/*
** kernel.c - Kernel module suppliment
**
** See Copyright Notice in mruby.h
*/

#include "mruby.h"
#include "mruby/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

mrb_value
mrb_exec_command(mrb_state *mrb, mrb_value obj)
{
  mrb_value command_str;
  mrb_get_args(mrb, "o", &command_str);
  char *command_p = mrb_str_to_cstr(mrb, command_str);
  char result_buff[BUF_SIZE];
  FILE *fp;
  mrb_value buff_str;

  if ( (fp = popen(command_p, "r")) == NULL) {
    return mrb_nil_value();
  }

  mrb_value str = mrb_obj_new(mrb, mrb_class_get(mrb, "String"), 0, NULL);

  while(fgets(result_buff, BUF_SIZE, fp) != NULL) {
    buff_str = mrb_str_new_cstr(mrb, result_buff);
    mrb_str_concat(mrb, str, buff_str);
  }
  (void) pclose(fp);

  return str;
}

mrb_value
mrb_system_command(mrb_state *mrb, mrb_value obj)
{
  mrb_value command_str;
  mrb_get_args(mrb, "o", &command_str);
  char *command_p = mrb_str_to_cstr(mrb, command_str);

  if (system(command_p) == 0) {
    return mrb_bool_value(1);
  } 
  else {
    return mrb_bool_value(0);
  }
}

void
mrb_mruby_syscommand_gem_init(mrb_state* mrb)
{
  struct RClass *krn;

  if (mrb->kernel_module == NULL) {
    mrb->kernel_module = mrb_define_module(mrb, "Kernel");
  }

  krn = mrb->kernel_module;
  mrb_define_method(mrb, krn, "mrb_exec_command", mrb_exec_command, 
		    MRB_ARGS_REQ(1));
  mrb_define_method(mrb, krn, "mrb_system_command", mrb_system_command, 
		    MRB_ARGS_REQ(1));
}

void
mrb_mruby_syscommand_gem_final(mrb_state* mrb)
{
  /* nothing to do. */
}

