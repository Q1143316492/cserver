export BUILD_ROOT = $(shell pwd)
export INCLUDE_PATH = $(BUILD_ROOT)/_include
export DEBUG = true

BUILD_DIR = $(BUILD_ROOT)/net/  \
			$(BUILD_ROOT)/proc/ \
			$(BUILD_ROOT)/app/ 
