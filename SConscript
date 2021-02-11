from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()

# The set of source files associated with this SConscript file.

src = []

if GetDepend('ANV_TESTSUIT_USING_EXAMPLE'):
	src    += Glob('anv_testsuit_example.c')

LOCAL_CCFLAGS = ''
path   =  [cwd]

group = DefineGroup('anv_testsuit', src, CPPPATH = path, depend = ['PKG_USING_ANV_TESTSUIT'], LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
