.PHONY: clean All

All:
	@echo "----------Building project:[ UnitTest - Debug ]----------"
	@cd "UnitTest" && $(MAKE) -f  "UnitTest.mk"
clean:
	@echo "----------Cleaning project:[ UnitTest - Debug ]----------"
	@cd "UnitTest" && $(MAKE) -f  "UnitTest.mk" clean
