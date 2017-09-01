import distutils.sysconfig
               
env = Environment(CPPFLAGS=['-std=c++0x'],
                  SWIGFLAGS=['-python', '-shadow', '-c++', '-py3'],
		  SHLIBPREFIX='_',
                  #CPPPATH=[distutils.sysconfig.get_python_inc()],
                  CPPPATH=['/usr/include/python3.6m', '.'],
                  )

complex = env.SharedObject('complex.cpp')

embed = env.Program('embed_example', ['embed_example.cpp', complex],LIBS=['python3.6m'])

swigEnv = env.Clone()

swigEnv.AppendUnique( SHLINKFLAGS = ['-rdynamic'] )

env.LoadableModule( '_complexmodule', ['complex.i', complex])


