SELECT    Weather.Id FROM
	Weather join Weather w 
ON datediff(Weather.RecordDate,w.RecordDate) = 1 
and Weather.Temperature > w.Temperature;

