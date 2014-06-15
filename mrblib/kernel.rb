module Kernel

  def system(*args)
    args_line = args.join("\s")
    mrb_system_command(args_line)
  end

  def exec_command(command)
    mrb_exec_command(command)
  end

end
