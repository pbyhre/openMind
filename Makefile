.PHONY: clean All

All:
	@echo "----------Building project:[ math - Debug ]----------"
	@cd "math" && $(MAKE) -f  "math.mk"
clean:
	@echo "----------Cleaning project:[ math - Debug ]----------"
	@cd "math" && $(MAKE) -f  "math.mk" clean
