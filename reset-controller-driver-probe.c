/* This driver is still under development, it might contains mistakes :)*/
static struct reset_control_ops meson_reset_ops = {
    .assert   = meson_reset_assert,
    .deassert = meson_reset_deassert,
    .status = meson_reset_status,
};

static int meson_reset_probe(struct platform_device *pdev)
{
    struct meson_reset_data *priv;

    priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
    if (!priv)
        return -ENOMEM;
    /* Map physical memory region to low memory and do other stuffs */
    [...]
    priv->rcdev.owner = THIS_MODULE;
    priv->rcdev.nr_resets = 4 * 32;
    priv->rcdev.ops = &meson_reset_ops;
    priv->rcdev.of_node = pdev->dev.of_node;
    priv->rcdev.of_reset_n_cells = 1;
    return reset_controller_register(&priv->rcdev);
}

static int meson_reset_remove(struct platform_device *pdev)
{
    struct meson_reset_data *priv = platform_get_drvdata(pdev);

    reset_controller_unregister(&priv->rcdev);
    return 0;
}

