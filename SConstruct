import distutils.sysconfig
               
env = Environment(CPPFLAGS=['-std=c++0x'],
                  SWIGFLAGS=['-python', '-shadow', '-c++'],
		  SHLIBPREFIX='_',
                  CPPPATH=[distutils.sysconfig.get_python_inc()],
                  )

complex = env.SharedObject('complex.cpp')

swigEnv = env.Clone()
swigEnv.AppendUnique( SHLINKFLAGS = ['-rdynamic'] )

swigEnv.LoadableModule( '_complexmodule', ['complex.i', complex])


