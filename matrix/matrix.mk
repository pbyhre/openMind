##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=matrix
ConfigurationName      :=Debug
WorkspacePath          := "/Users/petebyhre/dev/projects/openMind"
ProjectPath            := "/Users/petebyhre/dev/projects/openMind/matrix"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Pete Byhre
Date                   :=2014-09-29
CodeLitePath           :="/Users/petebyhre/Library/Application Support/codelite"
LinkerName             :=/usr/bin/clang++ 
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="matrix.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)$(WorkspacePath)/include  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)$(WorkspacePath)/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++ 
CC       := /usr/bin/clang 
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/Users/petebyhre/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/Matrix.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/Users/petebyhre/dev/projects/openMind/.build-debug"
	@echo rebuilt > "/Users/petebyhre/dev/projects/openMind/.build-debug/matrix"

./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Matrix.cpp$(ObjectSuffix): Matrix.cpp $(IntermediateDirectory)/Matrix.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/petebyhre/dev/projects/openMind/matrix/Matrix.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Matrix.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Matrix.cpp$(DependSuffix): Matrix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Matrix.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Matrix.cpp$(DependSuffix) -MM "Matrix.cpp"

$(IntermediateDirectory)/Matrix.cpp$(PreprocessSuffix): Matrix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Matrix.cpp$(PreprocessSuffix) "Matrix.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/matrix"

