// Hàm băm sử dụng thuật toán MD5 (Message Digest Algorithm 5)
function md5Hash(message){
  let hash = "";
  // Mã hóa chuỗi thông điệp thành dạng hex
  function encodeToHex(data){
    let result = "";
    for (let i = 0; i < data.length; i++) {
      result += ("0" + data.charCodeAt(i).toString(16)).slice(-2);
    }
    return result;
  }
  // Thuật toán MD5
  function md5Algorithm(message) {
    let rotateLeft = (x, n) => (x << n) | (x >>> (32-n));
    let FF = (a, b, c, d, x, s, t) => {
      a = b + rotateLeft((a + ((b & c) | (~b & d)) + x + t), s);
      return a & 0xFFFFFFFF;
    };
    // Create the variables
    let a = 0x67452301;
    let b = 0xEFCDAB89;
    let c = 0x98BADCFE;
    let d = 0x10325476;
    // Chia chuỗi thông điệp thành các khối 512-bit (64-byte)
    let chunks = [];
    for(let i = 0; i < message.length; i += 64){
      chunks.push(message.slice(i, i+64));
    }
    // Thực hiện các vòng lặp xử lý trên từng khối
    chunks.forEach(chunk => {
      let words = [];
      for(let i = 0; i < 64; i += 4){
        words.push(chunk.charCodeAt(i) | (chunk.charCodeAt(i+1) << 8) | (chunk.charCodeAt(i+2) << 16) | (chunk.charCodeAt(i+3) << 24));
      }
      let AA = a, BB = b, CC = c, DD = d;
      // Round 1
      a = FF(a, b, c, d, words[0],  7, 0xd76aa478);
      d = FF(d, a, b, c, words[1], 12, 0xe8c7b756);
      c = FF(c, d, a, b, words[2], 17, 0x242070db);
      b = FF(b, c, d, a, words[3], 22, 0xc1bdceee);
      a = FF(a, b, c, d, words[4],  7, 0xf57c0faf);
      d = FF(d, a, b, c, words[5], 12, 0x4787c62a);
      c = FF(c, d, a, b, words[6], 17, 0xa8304613);
      b = FF(b, c, d, a, words[7], 22, 0xfd469501);
      a = FF(a, b, c, d, words[8],  7, 0x698098d8);
			// Round 2
			a = FF(a, b, c, d, words[9], 12, 0x8b44f7af);
      d = FF(d, a, b, c, words[10], 17, 0xffff5bb1);
      c = FF(c, d, a, b, words[11], 22, 0x895cd7be);
      b = FF(b, c, d, a, words[12], 7, 0x6b901122);
      a = FF(a, b, c, d, words[13], 12, 0xfd987193);
      d = FF(d, a, b, c, words[14], 17, 0xa679438e);
      c = FF(c, d, a, b, words[15], 22, 0x49b40821);
      // Round 3
      a = GG(a, b, c, d, words[1], 5, 0xf61e2562);
      d = GG(d, a, b, c, words[6], 9, 0xc040b340);
      c = GG(c, d, a, b, words[11], 14, 0x265e5a51);
      b = GG(b, c, d, a, words[0], 20, 0xe9b6c7aa);
      a = GG(a, b, c, d, words[5], 5, 0xd62f105d);
      d = GG(d, a, b, c, words[10], 9, 0x02441453);
      c = GG(c, d, a, b, words[15], 14, 0xd8a1e681);
      b = GG(b, c, d, a, words[4], 20, 0xe7d3fbc8);
      a = GG(a, b, c, d, words[9], 5, 0x21e1cde6);
      d = GG(d, a, b, c, words[14], 9, 0xc33707d6);
      c = GG(c, d, a, b, words[3], 14, 0xf4d50d87);
      b = GG(b, c, d, a, words[8], 20, 0x455a14ed);
      a = GG(a, b, c, d, words[13], 5, 0xa9e3e905);
      d = GG(d, a, b, c, words[2], 9, 0xfcefa3f8);
      c = GG(c, d, a, b, words[7], 14, 0x676f02d9);
      b = GG(b, c, d, a, words[12], 20, 0x8d2a4c8a);
			// Round 4
			function GG(a, b, c, d, x, s, t){
				a = a + ((b ^ d) | (c & d)) + x + t;  
				a = ((a << s) | (a >>> (32 - s))) + b;
				return a & 0xFFFFFFFF;
			}
			a = GG(a, b, d, words[5], 4, 0xfa3942);
			b = GG(a, b, c, words[8], 11, 0x877f681);
			c = GG(c, d, a, words[11], 16, 0x69d6122);
			d = GG(b, c, d, words[14], 23, 0xfde5380c);
			a = GG(a, b, c, d, words[1], 4, 0xa4beea44b); 
			b = GG(d, a, b, c, words[4], 11, 0x4bdecfa9);
			c = GG(c, d, a, b, words[7], 16, 0xf6bb4b60);
			d = GG(b, c, d, a, words[10], 23, 0xbebfbc70);
			a = GG(a, b, c, d, words[13], 4, 0x289b7ec6);
			b = GG(d, a, b, c, words[0], 11, 0xeaa127fa);
			c = GG(c, d, a, b, words[3], 16, 0xd4ef3085);
			d = GG(b, c, d, a, words[6], 23, 0x04881d05);
			a = GG(a, b, c, d, words[9], 4, 0xd9d4d039);
			b = GG(d, a, b, c, words[12], 11, 0xe6db99e5);
			c = GG(c, d, a, b, words[15], 16, 0x1fa27cf8);
			d = GG(b, c, d, a, words[2], 23, 0xc4ac5665);
			// Round 5
			function HH(a, b, c, d, x, s, t){
				a = a + (b ^ c ^ d) + x + t;
				a = ((a << s) | (a >>> (32 - s))) + b;
				return a & 0xFFFFFFFF;
			}
			a = HH(a, b, c, d, words[0], 6, 0xf4292244);
			b = HH(d, a, b, c, words[7], 10, 0x432aff97);
			c = HH(c, d, a, b, words[14], 15, 0xab9423a7);
			d = HH(b, c, d, a, words[5], 21, 0xfc93a039);
			a = HH(a, b, c, d, words[12], 6, 0x655b59c3);
			b = HH(d, a, b, c, words[3], 10, 0x8f0ccc92);
			c = HH(c, d, a, b, words[10], 15, 0xffeff47d);
			d = HH(b, c, d, a, words[1], 21, 0x85845dd1);
			a = HH(a, b, c, d, words[8], 6, 0x6fa87e4f);
			b = HH(d, a, b, c, words[15], 10, 0xfe2ce6e0);
			c = HH(c, d, a, b, words[6], 15, 0xa3014314);
			d = HH(b, c, d, a, words[13], 21, 0x4e0811a1);
			a = HH(a, b, c, d, words[4], 6, 0xf7537e82);
			b = HH(d, a, b, c, words[11], 10, 0xbd3af235);
			c = HH(c, d, a, b, words[2], 15, 0x2ad7d2bb);
			d = HH(b, c, d, a, words[9], 21, 0xeb86d391);
			// Final addition
			a = (a + AA) & 0xFFFFFFFF;
			b = (b + BB) & 0xFFFFFFFF;
			c = (c + CC) & 0xFFFFFFFF;
			d = (d + DD) & 0xFFFFFFFF;
			// Combine the result
			var result = hex(a) + hex(b) + hex(c) + hex(d);
			console.log(result);
		})
	}
}