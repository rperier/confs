int consumer_device_probe(struct platform_device *pdev)
{
	struct reset_control *rstc = NULL;
	
	/* Do some initializations and allocations for your driver */
	[...]

	rstc = of_reset_control_get(pdev->dev.of_node, NULL);

	if (IS_ERR(rstc)) {
    		pr_err("Unable to load reset line from device tree\n");
    		return PTR_ERR(rstc);
	}

	reset_control_assert(rstc);
	udelay(10);
	reset_control_deassert(rstc);

	reset_control_put(rstc);
	return 0;
}
