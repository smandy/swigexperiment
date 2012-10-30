import distutils.sysconfig
               
env = Environment(CPPFLAGS=['-std=c++0x'],
    SWIGFLAGS=['-python', '-shadow', '-c++'],
    CPPPATH=[distutils.sysconfig.get_python_inc()],
    SHLIBPREFIX="" )

complex = env.Object('complex.cpp')
complex = env.SharedObject('complex.cpp')


swigEnv = env.Clone()
swigEnv.AppendUnique( SHLINKFLAGS = ['-rdynamic'] )

cp = env.Program("complexTest.cpp", LIBS=[complex])
swigEnv.LoadableModule( '_complexmodule.so', ['complex.i', complex])
