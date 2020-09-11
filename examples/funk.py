""" Ein Modul mit Funtionen aus der Funktechnik """

def lambda2freq(lamb, c=3e8):
    """Berechnet die Frequenz aus der Wellenlänge in verscgiedenen Medien"""
    return c / lamb
    
def freq2lambda(freq, c=3e8):
    """Berechnet die Wellenlänge aus der Frequenz in verschiedenen Medien"""
    return c / freq

def period2freq(p):
	""" Berechnet die Frequenz aus einer gegebenen Periodendauer """
	return 1/p	
	
def freq2period(f):
	""" Berechnet die Periodendauer aus einer gegebenen Frequenz """
	return 1/f	

def ratio_u2db(u_aus,u_ein):
	"""Berechnet Dezibel aus dem Spannungsverhältnis"""
    return 20*math.log10(u_aus/u_ein)

def db2ratio_u(dezibel):
	"""Berechnet Spannungsverhältnis aus Dezibel"""
    return 10**(dezibel/20)

def ratio_p2db(p_aus,p_ein):
	"""Berechnet Dezibel aus Leistungsverhältnis"""
    return 10*math.log10(p_aus/p_ein)

def db2ratio_p(dezibel):
	"""Berechnet Leistungsverhältnis aus Dezibel"""
    return 10**(dezibel/10)
