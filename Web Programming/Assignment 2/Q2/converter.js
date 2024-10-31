var conversionRates = {
    usd: { usd: 1, gbp: 0.49246, cad: 0.98054, eur: 0.70641, aud: 1.13262 },
    gbp: { usd: 2.03032, gbp: 1, cad: 1.99169, eur: 1.43448, aud: 2.29964 },
    cad: { usd: 1.01941, gbp: 0.50221, cad: 1, eur: 0.72037, aud: 1.15498 },
    eur: { usd: 1.41544, gbp: 0.69714, cad: 1.38814, eur: 1, aud: 1.60329 },
    aud: { usd: 0.88297, gbp: 0.43497, cad: 0.86613, eur: 0.62382, aud: 1 }
};

function convertCurrency(baseCurrency) {
    const baseValue = parseFloat(document.getElementById(baseCurrency).value);

    if (isNaN(baseValue)) {
        return; 
    }

    
    for (const currency in conversionRates[baseCurrency]) {
        if (currency !== baseCurrency) {
            const convertedValue = (baseValue * conversionRates[baseCurrency][currency]).toFixed(2);
            document.getElementById(currency).value = convertedValue;
        }
    }
}