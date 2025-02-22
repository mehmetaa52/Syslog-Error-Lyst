# Syslog-Error-Lyst

Proje Açıklaması
Bu proje, Linux işletim sisteminde syslog kayıtlarını okumak ve çift yönlü bağlı liste kullanarak sadece "ERROR" içeren kayıtları ekrana yazdırmak amacıyla geliştirilmiştir.

# Syslog Nedir?
Syslog, Linux sisteminde olayları ve mesajları kaydeden bir günlükleme sistemidir.Log dosyaları /var/log/syslog içinde tutulur ve "ROOT" yetkisiyle erişilebilir.Sistem yöneticileri hataları ve olayları analiz ederek sorunları görebilir.
# Bağlı liste nedir? Tek Yönlü , Çift Yönlü Bağlı liste nedir?
Bağlı liste nedir?
Bağlı	liste,	elemanların	bellekte	ardışık	olmayan	konumlarda	saklandığı	ve	her	bir	elemanın	bir	sonraki	elemanın	adresini	tuttuğu	dinamik	bir	veri	yapısıdır.
Her	bir	eleman	(düğüm/node)	iki	kısımdan	oluşur:	- Veri	bölümü	(data)	- Bağlantı	bölümü	(pointer/link)
Tek Yönlü , Çift Yönlü ve Döngüsel Bağlı liste nedir?
Tek Yönlü Bağlı Liste'de her	düğüm	sadece	kendinden	sonraki	düğümün	adresini	tutar. 
Yalnızca tek	yönlü	hareket (ileri	yönde) edilebilir.
Bellek	kullanımı	diğer	türlere	göre	daha	azdır.
Geriye	dönük	işlemler	için	liste	başından	tarama	gerekir.
Çift Yönlü Bağlı Liste'de her	düğüm	hem	önceki	hem	de	sonraki	düğümün	adresini	tutar.
İki	yönlüde (ileri	ve	geri)	hareket	edilebilir.	
Silme	işlemleri	daha	kolaydır.
Daha	fazla	bellek	kullanır.
# Kullanım
Kodları derleyin ve çalıştırın.
Not: Syslog dosyasına erişim için root yetkisi gerekebilir.
# Çalışma Mantığı
Syslog dosyası (/var/log/syslog) satır satır okunur.
Eğer satır "ERROR" kelimesini içeriyorsa, kayıt bağlı listeye eklenir.
Bağlı listedeki kayıtlar ekrana yazdırılır.
Bellek sızıntısını önlemek için dinamik olarak ayrılan bellek temizlenir.
