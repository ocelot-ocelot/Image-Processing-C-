lena = dlmread('lena.txt');
lena_neg = dlmread("lena_neg.txt");
lena_change = dlmread("lena_changeVal.txt");

peppers = dlmread('peppers.txt');
peppers_neg = dlmread("peppers_neg.txt");
peppers_change = dlmread("peppers_changeVal.txt");

tiledlayout(2,3);
nexttile, imagesc(lena), colormap(gray), title("Original Image");
nexttile, imagesc(lena_neg), colormap(gray), title("Negative Image");
nexttile, imagesc(lena_change), colormap(gray), title("Shifted Image");
nexttile, imagesc(peppers), colormap(gray), title("Original Image");
nexttile, imagesc(peppers_neg), colormap(gray), title("Negative Image");
nexttile, imagesc(peppers_change), colormap(gray), title("Shifted Image");