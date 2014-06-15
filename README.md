#mruby-syscommand   [![Build Status](https://travis-ci.org/hiroeorz/mruby-syscommand.svg?branch=master)](https://travis-ci.org/hiroeorz/mruby-syscommand)


System Command Library.

##Installing

Write in /mruby/build_config.rb

```ruby
MRuby::Build.new do |conf|

  conf.gem :github => 'hiroeorz/mruby-syscommand', :branch => 'master'

end
```

##Examples

###system(command)

```ruby
> system("ls")

AUTHORS			Rakefile		include
CONTRIBUTING.md		TODO			minirake
ChangeLog		benchmark		mrbgems
INSTALL			bin			mrblib

 => true
```

```ruby
> system("ls", "-a")

.			Makefile		examples
..			NEWS			include
.git			README.md		minirake
.gitignore		Rakefile		mrbgems
.travis.yml		TODO			mrblib
AUTHORS			benchmark		src
CONTRIBUTING.md		bin			tasks
ChangeLog		build			test
INSTALL			build_config.rb		tools
LEGAL			build_config.rb.all	travis_config.rb
MITL			doc

 => true
```

Return value is true, when exit status is 0, otherwise return value is false. 

```ruby
> system("ls /neko")

ls: /neko: No such file or directory

 => false
```

###exec_command

```ruby
> str = exec_command("ls")

 => "AUTHORS\nCONTRIBUTING.md\nChangeLog\nINSTALL\nLEGAL\nMITL\nMakefile\n
NEWS\nREADME.md\nRakefile\nTODO\nbenchmark\nbin\nbuild\nbuild_config.rb\n
build_config.rb.all\ndoc\nexamples\ninclude\nminirake\nmrbgems\nmrblib\nsrc\n
tasks\ntest\ntools\ntravis_config.rb\n"
```

Return value is result of execute command.
