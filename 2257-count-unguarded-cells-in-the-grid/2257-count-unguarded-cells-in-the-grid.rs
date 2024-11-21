impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (m as usize, n as usize);
        let mut map = vec![vec!['U'; n]; m];
        let dn = vec![(0, 1), (1, 0), (-1, 0), (0, -1)];
                
        for guard in &guards { 
            map[guard[0] as usize][guard[1] as usize] = 'G'; 
        }
        for wall in &walls { 
            map[wall[0] as usize][wall[1] as usize] = 'W'; 
        }
        
        for i in 0..m {
            for j in 0..n {
                if map[i][j] == 'G' {
                    for &(di, dj) in &dn {
                        let (mut ni, mut nj) = (i as i32 + di, j as i32 + dj);
                        
                        while ni >= 0 && ni < m as i32 && nj >= 0 && nj < n as i32 {
                            let (ni_usize, nj_usize) = (ni as usize, nj as usize);
                            
                            if map[ni_usize][nj_usize] == 'W' || map[ni_usize][nj_usize] == 'G' {
                                break;
                            }
                            
                            if map[ni_usize][nj_usize] == 'U' {
                                map[ni_usize][nj_usize] = 'V';
                            }
                            
                            ni += di;
                            nj += dj;
                        }
                    }
                }
            }
        }
        
        map.iter()
           .flatten()
           .filter(|&&cell| cell == 'U')
           .count() as i32
    }
}