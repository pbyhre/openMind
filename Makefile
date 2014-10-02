.PHONY: clean All

All:
	@echo "----------Building project:[ core - Debug ]----------"
	@cd "core" && $(MAKE) -f  "core.mk"
	@echo "----------Building project:[ UnitTest - Debug ]----------"
	@cd "UnitTest" && $(MAKE) -f  "UnitTest.mk"
clean:
	@echo "----------Cleaning project:[ core - Debug ]----------"
	@cd "core" && $(MAKE) -f  "core.mk"  clean
	@echo "----------Cleaning project:[ UnitTest - Debug ]----------"
	@cd "UnitTest" && $(MAKE) -f  "UnitTest.mk" clean
